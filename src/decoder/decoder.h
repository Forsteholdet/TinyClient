

#ifndef TINY_CLIENT_DECODER_H
#define TINY_CLIENT_DECODER_H

#include "response/response.h"
#include "package/package.h"


class Decoder{

public:

    Response decode(Package _package)
    {

        this->package = _package;

        this->statusCode = findStatusCode();
        
        this->jsonBody = decodeBodyToJson();
        
        return Response(statusCode, "hello");
    }

    bourne::json getJsonBody(){
        return this->jsonBody;
    }


    int getStatusCode(){
        return this->statusCode;
    }

private:
    Package package;

    int statusCode;

    bourne::json jsonBody;

    int findStatusCode()
    {
        TinyString header = package.getHeader();

        int firstWhiteSpace = header.find(" ");
        int whiteSpaceAfterStatusCode = firstWhiteSpace + 4;

        TinyString statusCodeString = header.substr(firstWhiteSpace, whiteSpaceAfterStatusCode);

        int statusCode = atoi(statusCodeString.toCharArray());
        
        return statusCode;
    }


    TinyString findBody(){return "default";}

    bourne::json decodeBodyToJson()
    {   TinyString stringBody = package.getBody();
   
        TinyString prepStringBody = "\"" + stringBody + "\"";

        const char* bodyToParse = prepStringBody.toCharArray();

        auto jsonBody = bourne::json::parse(bodyToParse);

        return jsonBody;
    }

};

#endif 