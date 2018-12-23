//////////////////////////////////////////////////////
///     DS18b20
//////////////////////////////////////////////////////

void INIT_DS18B20(int precision)
{
  temperatureSensors.begin();

  int available = temperatureSensors.getDeviceCount();

  for (int x = 0; x != available; x++)
  {
    if (temperatureSensors.getAddress(DS18B20[x], x))
    {
      temperatureSensors.setResolution(DS18B20[x], precision);
    }
  }
}

int DS18B20_CELSIUS(int address)
{
  if (temperatureSensors.getAddress(DS18B20[address], address))
  {
    temperatureSensors.requestTemperatures();
    return temperatureSensors.getTempC(DS18B20[address]);
  }
  else
    return 0;
}

