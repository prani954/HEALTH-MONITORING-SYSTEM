import 'package:firebase_auth/firebase_auth.dart';
import 'package:firebase_database/firebase_database.dart';
import 'package:flutter/material.dart';
import 'package:gizmoconn/screens/patient_screen.dart';
import 'package:gizmoconn/widgets/textfield.dart';
import '../utils/color_utils.dart.dart';

class SiginScreen extends StatefulWidget {
  const SiginScreen({super.key});

  @override
  State<SiginScreen> createState() => _SiginScreenState();
}

class _SiginScreenState extends State<SiginScreen> {
  final TextEditingController _passwordTextController = TextEditingController();
  final TextEditingController _emailTextController = TextEditingController();
  final databaseReference = FirebaseDatabase.instance.ref();
  static Future<void> printData() async {
    DatabaseReference reference =
        FirebaseDatabase.instance.ref();

    final snapshot = await reference.get(); // you should use await on async methods
    if (snapshot!.value != null) {
      print( snapshot.value);
    }
  }
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Container(
        height: MediaQuery.of(context).size.height,
        decoration: BoxDecoration(
          gradient: LinearGradient(colors: [
            hexStringToColor('CB2B93'),
            hexStringToColor('9546C4'),
            hexStringToColor('5E61F4')
          ], begin: Alignment.topCenter, end: Alignment.bottomCenter),
        ),
        child: SingleChildScrollView(
          child: Column(
            children: [
              Container(
                height: 400,
                
                decoration: const BoxDecoration(
                  image: DecorationImage(
                    image: AssetImage("assets/images/medicore.jpg"),
                    fit: BoxFit.fitHeight
                  )
                ),
                //child: Image.asset('assets/images/medicore.jpg'),
              ),
              const SizedBox(height: 10),
              reusableTextField('Enter Email Id', Icons.person_outlined, false,
                  _emailTextController),
              const SizedBox(height: 20),
              reusableTextField('Enter password', Icons.lock_outline, true,
                  _passwordTextController),
              const SizedBox(height: 10),
              Container(
                child: ElevatedButton(
                  onPressed: (() {
                    FirebaseAuth.instance
                        .signInWithEmailAndPassword(
                            email: _emailTextController.text,
                            password: _passwordTextController.text)
                        .then((value) =>
                            Navigator.of(context).pushNamed('/patient'))
                        .onError((error, stackTrace) {
                          print(error);
                          const AlertDialog(
                              title: Text('Error'),
                              content: Text('Invalid UserName/Password'),
                            );
                        });
                  }),
                  child: const Text('SIGN IN'),
                ),
              ),
              const SizedBox(
                height: 10,
              ),
              ElevatedButton(
                onPressed: () {
                  Navigator.of(context).pushNamed('/sign up');
                },
                child: const Text('SIGN UP'),
              )
            ],
          ),
        ),
      ),
    );
  }
}
