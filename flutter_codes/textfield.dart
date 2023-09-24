import 'package:flutter/material.dart';

TextField reusableTextField(String text, IconData icon, bool isPasswordType,
    TextEditingController controller) {
  return TextField(
    controller: controller,
    obscureText: isPasswordType,
    autocorrect: !isPasswordType,
    decoration: InputDecoration(
      labelStyle: const TextStyle(color: Colors.white),
      labelText: text,
      prefixIcon: Icon(
        icon,
        color: Colors.white70,
      ),
      border: const OutlineInputBorder(
        borderRadius: BorderRadius.all(Radius.circular(30)),
      ),
    ),
  );
}
