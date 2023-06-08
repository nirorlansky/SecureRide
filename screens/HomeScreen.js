import React from 'react';
import { View, Text, Button } from 'react-native';
import { useNavigation } from '@react-navigation/native';

const HomeScreen = () => {
    const navigation = useNavigation();
  
    const goToVehicleDetails = () => {
      navigation.navigate('VehicleDetails');
    };
  
    return (
      <View>
        <Text>Welcome to Secure Ride App!</Text>
        <Button title="View Vehicle Details" onPress={goToVehicleDetails} />
      </View>
    );
  };
  export default HomeScreen