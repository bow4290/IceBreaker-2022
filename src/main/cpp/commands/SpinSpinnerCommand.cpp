
#include "commands/SpinSpinnerCommand.h"
#include "subsystems/SpinnerSubsystem.h"

SpinSpinnerCommand::SpinSpinnerCommand(SpinnerSubsystem* subsystem)
: spinnerMotor{subsystem}{
    AddRequirements({subsystem});
}

void SpinSpinnerCommand::Initialize(){
}

void SpinSpinnerCommand::Execute(){
  spinnerMotor->Spin(1);
}

void SpinSpinnerCommand::End(bool interrupted){
  spinnerMotor->StopSpin();
}

bool SpinSpinnerCommand::IsFinished(){
  return false;
}
