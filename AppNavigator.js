import React from 'react';
import { createStackNavigator } from '@react-navigation/stack';

import HomeScreen from './screens/HomeScreen';
import VehicleDetailsScreen from './screens/VehicleDetailsScreen';
import RegistrationsScreen from './screens/RegistrationsScreen';

const Stack = createStackNavigator();

const AppNavigator = () => {
  return (
    <Stack.Navigator>
      <Stack.Screen name="Home" component={HomeScreen} />
      <Stack.Screen name="VehicleDetails" component={VehicleDetailsScreen} />
      <Stack.Screen name="Registrations" component={RegistrationsScreen} />
    </Stack.Navigator>
  );
};

export default AppNavigator;
