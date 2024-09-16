// OTUS Learn Project. Made by Alex Sinkin (c)

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"


class FInventoryModule : public IModuleInterface
{
public:

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};