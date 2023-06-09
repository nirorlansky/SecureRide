import React from 'react';
import { View, Text } from 'react-native';
import MapView from 'react-native-maps';


const RegistrationsScreen = () => {
    return (
        <MapView
          style={{ flex: 1 }}
          initialRegion={{
            latitude: 32.111767,
            longitude: 34.801361,
            latitudeDelta: 0.0922,
            longitudeDelta: 0.0421,
          }}
        />
      );
};

export default RegistrationsScreen;
