import 'package:firebase_core/firebase_core.dart';
import 'package:flutter/material.dart';
import 'package:gizmoconn/screens/patient_screen.dart';
import 'package:gizmoconn/screens/sigin_screen.dart';
import 'package:gizmoconn/screens/signup_screen.dart';

void main() async{
  WidgetsFlutterBinding.ensureInitialized();
  await Firebase.initializeApp();
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Gizmoconn',
      home: SiginScreen(),
      debugShowCheckedModeBanner: false,
      routes: {
        '/patient': (context) => Patient_screen(),
        '/sign up': (context) => SignUp()
      },
    );
  }
}
