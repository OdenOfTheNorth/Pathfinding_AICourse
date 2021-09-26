// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FGAI_2GameModeBase.generated.h"

class UAStar;
class AMyGrid;
/**
 * 
 */
UCLASS()
class FGAI_2_API AFGAI_2GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	AMyGrid* grid = nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<UAStar*> AStarComponents;
};
