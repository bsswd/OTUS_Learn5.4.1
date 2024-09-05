// OTUS Learn Project. Made by Alex Sinkin (c)

#include "Widgets/ItemTooltipWidget.h"


TMap<FString, float> UItemTooltipWidget::GetStatMap(const FItemStruct InItem)
{
	TMap<FString, float> ResultingMap = {

		{" Maximum Health", InItem.HealthValue},
		{" Shield", InItem.ShieldValue}
	};

	return ResultingMap;
}