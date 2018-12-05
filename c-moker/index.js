const admin = require('firebase-admin')

var serviceAccount = require('./khalil-dab1c-firebase-adminsdk-peim5-a9a1707b5a.json')
var api = require('./api.json')

admin.initializeApp({
  credential: admin.credential.cert(serviceAccount),
  databaseURL: 'https://khalil-dab1c.firebaseio.com'
})

var db = admin.firestore()

var docRef = db.collection('vai_main_db').doc('user_arthur_rocha')

var setAda = docRef.update(api)
