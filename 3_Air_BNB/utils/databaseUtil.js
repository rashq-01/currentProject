const mongo = require('mongodb');

const MongoClient = mongo.MongoClient;

require('dotenv').config();
const MONGO_URL = process.env.MONGO_URL;

let _db;

const mongoConnect = (callback) => {

    MongoClient.connect(MONGO_URL).then(client => {
        callback();
        _db = client.db('airbnb');
    }).catch(err => {
        console.log('Error while connecting to Mongo: ',err);
    });
}

const getDB = () =>{
    if(!_db){
        throw new Error('Mongo not connected');
    }
    return _db;
}

exports.getDB = getDB;
exports.mongoConnect = mongoConnect;