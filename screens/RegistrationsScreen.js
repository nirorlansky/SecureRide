import React, { useState } from 'react';
import { View, Text, TextInput, Button } from 'react-native';

function RegistrationScreen({ navigation }) {
  const [fullName, setFullName] = useState('');
  const [email, setEmail] = useState('');
  const [vehicleType, setVehicleType] = useState('');
  const [serialNumber, setSerialNumber] = useState('');

  const handleSignUp = () => {
    // Perform signup logic with the collected data
    // For example, you can make an API call to register the user

    // After successful signup, navigate back to the HomeScreen
    navigation.navigate('Home');
  };

  return (
    <View>
      <Text>Full Name</Text>
      <TextInput
        value={fullName}
        onChangeText={setFullName}
        placeholder="Enter your full name"
      />

      <Text>Email</Text>
      <TextInput
        value={email}
        onChangeText={setEmail}
        placeholder="Enter your email"
      />

      <Text>Vehicle Type</Text>
      <TextInput
        value={vehicleType}
        onChangeText={setVehicleType}
        placeholder="Enter your vehicle type"
      />

      <Text>Serial Number</Text>
      <TextInput
        value={serialNumber}
        onChangeText={setSerialNumber}
        placeholder="Enter your serial number"
      />

      <Button title="Submit" onPress={handleSignUp} />
    </View>
  );
}

export default RegistrationScreen;
