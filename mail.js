
//Get this file:///C:/Users/joshp/OneDrive/Documents/University/SIT210/Task%204.2HD/Test/index.html
// Your web app's Firebase configuration
const firebaseConfig = {
  apiKey: "ApiKey",
  authDomain: "authDomain",
  databaseURL: "dbURL",
  projectId: "test2-f11da",
  storageBucket: "test2-f11da.appspot.com",
  messagingSenderId: "messageid",
  appId: "appid"
};


// initialize firebase
firebase.initializeApp(firebaseConfig);

// reference your database
var contactFormDB = firebase.database().ref("light");


document.getElementById("contactForm").addEventListener('change', submitForm);



function submitForm(e) {
  e.preventDefault();

  var blue = document.querySelector('input[name="Blue"]:checked').value;
  var green = document.querySelector('input[name="Green"]:checked').value;
  var red = document.querySelector('input[name="Red"]:checked').value;

  saveMessages(blue, green, red);
  
  document.querySelector(".alert").style.display = "block";

  //   remove the alert
  setTimeout(() => {
    document.querySelector(".alert").style.display = "none";
  }, 3000);

  //   reset the form
  document.getElementById("contactForm").reset();
}

const saveMessages = (blue, green, red) => {
  // var newContactForm = contactFormDB.push();

  contactFormDB.set({
    blue: blue,
    green: green,
    red: red,
  });
};
