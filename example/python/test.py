from flask import Flask
app = Flask(__name__)

@app.route('/')
def hello_world():
    return 'Hello, World!'

@app.route('/json')
def json_response():
    return {"Hello": "World"}

app.run()