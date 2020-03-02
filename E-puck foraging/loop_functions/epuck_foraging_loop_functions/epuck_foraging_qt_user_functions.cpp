#include "epuck_foraging_qt_user_functions.h"
#include <controllers/epuck_foraging/epuck_foraging.h>
#include <argos3/core/simulator/entity/controllable_entity.h>

using namespace argos;

/****************************************/
/****************************************/

CEPuckForagingQTUserFunctions::CEPuckForagingQTUserFunctions() {
   RegisterUserFunction<CEPuckForagingQTUserFunctions,CEPuckEntity>(&CEPuckForagingQTUserFunctions::Draw);
}

/****************************************/
/****************************************/

void CEPuckForagingQTUserFunctions::Draw(CEPuckEntity& c_entity) {
   CEPuckForaging& cController = dynamic_cast<CEPuckForaging&>(c_entity.GetControllableEntity().GetController());
   CEPuckForaging::SFoodData& sFoodData = cController.GetFoodData();
   if(sFoodData.HasFoodItem) {
      DrawCylinder(
         CVector3(0.0f, 0.0f, 0.3f),
         CQuaternion(),
         0.1f,
         0.05f,
         CColor::BLACK);
   }
}

/****************************************/
/****************************************/

REGISTER_QTOPENGL_USER_FUNCTIONS(CEPuckForagingQTUserFunctions, "epuck_foraging_qt_user_functions")
