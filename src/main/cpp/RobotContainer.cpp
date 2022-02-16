
#include "RobotContainer.h"

#include "commands/DefaultDrive.h"
#include <frc/XboxController.h>
#include "subsystems/DrivetrainSubsystem.h"
#include "commands/SpinSpinnerCommand.h"
#include <frc2/command/button/JoystickButton.h>

RobotContainer::RobotContainer(){
  ConfigureButtonBindings();

  drivetrainSubsystem.SetDefaultCommand(DefaultDrive(&drivetrainSubsystem,
                                [this] { return controller.GetLeftX(); },
                                [this] { return -controller.GetLeftY(); }));
}

void RobotContainer::ConfigureButtonBindings() {
  frc2::JoystickButton(&controller, 1).ToggleWhenPressed(SpinSpinnerCommand(&spinnerSubsystem));    // Button 1 = A Button
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  return nullptr;
}
