#include "lib/Duck/MallardDuck.h"
#include "lib/Duck/ModelDuck.h"
#include "lib/DuckFunctions.h"

int main()
{
	MallardDuck mallardDuck;
	PlayWithDuck(mallardDuck);
	PlayWithDuck(mallardDuck);

	ModelDuck modelDuck;
	PlayWithDuck(modelDuck);

	modelDuck.SetFlyBehavior(CreateFlyWithWings());
	PlayWithDuck(modelDuck);
	PlayWithDuck(modelDuck);

	modelDuck.SetFlyBehavior(CreateFlyWithWings());
	PlayWithDuck(modelDuck);

	return 0;
}
