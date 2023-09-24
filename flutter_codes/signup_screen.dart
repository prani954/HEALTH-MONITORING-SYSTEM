import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/material.dart';
import '../utils/color_utils.dart.dart';
import 'package:gizmoconn/widgets/textfield.dart';

class SignUp extends StatelessWidget {
  TextEditingController userName = TextEditingController();
  TextEditingController emailId = TextEditingController();
  TextEditingController password = TextEditingController();
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Container(
        decoration: BoxDecoration(
          gradient: LinearGradient(colors: [
            hexStringToColor('CB2B93'),
            hexStringToColor('9546C4'),
            hexStringToColor('5E61F4')
          ], begin: Alignment.topCenter, end: Alignment.bottomCenter),
        ),
        child: ListView(
          children: [
            SizedBox(
              height: 50,
            ),
            reusableTextField(
              'Enter User Name',
              Icons.person_outline,
              false,
              userName,
            ),
            SizedBox(
              height: 20,
            ),
            reusableTextField(
              'Enter Email Id',
              Icons.email,
              false,
              emailId,
            ),
            SizedBox(
              height: 20,
            ),
            reusableTextField(
              'Enter Password',
              Icons.lock,
              true,
              password,
            ),
            SizedBox(
              height: 20,
            ),
            Container(
              decoration: BoxDecoration(
                borderRadius: BorderRadius.circular(30),
              ),
              child: ElevatedButton(
                onPressed: () {
                  FirebaseAuth.instance
                      .createUserWithEmailAndPassword(
                          email: emailId.text, password: password.text)
                      .then(
                        (value) => Navigator.pushNamed(context, '/patient'),
                      )
                      .onError(
                        (error, stackTrace) => print('Error:${error.toString()}'),
                      );
                },
                child: Text('SIGN UP'),
              ),
            )
          ],
        ),
      ),
    );
  }
}
