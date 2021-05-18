
typedef struct ForzaData_s{
  int32_t IsRaceOn;
  
  uint32_t TimestampMS;

  float EngineMaxRpm;
  float EngineIdleRpm;
  float CurrentEngineRpm;
  
  float AccelerationX;
  float AccelerationY;
  float AccelerationZ;
  
  float VelocityX;
  float VelocityY;
  float VelocityZ;

  float AngularVelocityX;
  float AngularVelocityY;
  float AngularVelocityZ;

  float Yaw;
  float Pitch;
  float Roll;

  float NormalizedSuspensionTravelFrontLeft;
  float NormalizedSuspensionTravelFrontRight;
  float NormalizedSuspensionTravelRearLeft;
  float NormalizedSuspensionTravelRearRight;

  float TireSlipRatioFrontLeft; // Tire normalized slip ratio, = 0 means 100% grip and |ratio| > 1.0 means loss of grip.
  float TireSlipRatioFrontRight;
  float TireSlipRatioRearLeft;
  float TireSlipRatioRearRight;

  float WheelRotationSpeedFrontLeft; // Wheel rotation speed radians/sec.
  float WheelRotationSpeedFrontRight;
  float WheelRotationSpeedRearLeft;
  float WheelRotationSpeedRearRight;

  int32_t WheelOnRumbleStripFrontLeft; // = 1 when wheel is on rumble strip, = 0 when off.
  int32_t WheelOnRumbleStripFrontRight;
  int32_t WheelOnRumbleStripRearLeft;
  int32_t WheelOnRumbleStripRearRight;

  float WheelInPuddleDepthFrontLeft; // = from 0 to 1, where 1 is the deepest puddle
  float WheelInPuddleDepthFrontRight;
  float WheelInPuddleDepthRearLeft;
  float WheelInPuddleDepthRearRight;

  float SurfaceRumbleFrontLeft; // Non-dimensional surface rumble values passed to controller force feedback
  float SurfaceRumbleFrontRight;
  float SurfaceRumbleRearLeft;
  float SurfaceRumbleRearRight;

  float TireSlipAngleFrontLeft; // Tire normalized slip angle, = 0 means 100% grip and |angle| > 1.0 means loss of grip.
  float TireSlipAngleFrontRight;
  float TireSlipAngleRearLeft;
  float TireSlipAngleRearRight;

  float TireCombinedSlipFrontLeft; // Tire normalized combined slip, = 0 means 100% grip and |slip| > 1.0 means loss of grip.
  float TireCombinedSlipFrontRight;
  float TireCombinedSlipRearLeft;
  float TireCombinedSlipRearRight;

  float SuspensionTravelMetersFrontLeft; // Actual suspension travel in meters
  float SuspensionTravelMetersFrontRight;
  float SuspensionTravelMetersRearLeft;
  float SuspensionTravelMetersRearRight;

  int32_t CarOrdinal; //Unique ID of the car make/model
  int32_t CarClass; //Between 0 (D -- worst cars) and 7 (X class -- best cars) inclusive
  int32_t CarPerformanceIndex; //Between 100 (slowest car) and 999 (fastest car) inclusive
  int32_t DrivetrainType; //Corresponds to EDrivetrainType; 0 = FWD, 1 = RWD, 2 = AWD
  int32_t NumCylinders; //Number of cylinders in the engine

// [Sept. 10, 2018 UPDATE: NEW DATA OUT STRUCTURE]

// V1 is now called Sled
// V2 is V1 then these added in this order at the bottom.
// Position (meters)
  float PositionX;
  float PositionY;
  float PositionZ;

  float Speed; // meters per second
  float Power; // watts
  float Torque; // newton meter

  float TireTempFrontLeft;
  float TireTempFrontRight;
  float TireTempRearLeft;
  float TireTempRearRight;

  float Boost;
  float Fuel;
  float DistanceTraveled;
  float BestLap;
  float LastLap;
  float CurrentLap;
  float CurrentRaceTime;

  uint16_t LapNumber;
  uint8_t RacePosition;

  uint8_t Accel;
  uint8_t Brake;
  uint8_t Clutch;
  uint8_t HandBrake;
  uint8_t Gear;
  int8_t Steer;

  int8_t NormalizedDrivingLine;
  int8_t NormalizedAIBrakeDifference;
} ForzaData_t;
