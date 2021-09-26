// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

//#include <stdbool.h>

#include "MyGrid.h"
#include "Components/ActorComponent.h"
#include "AStar.generated.h"



class AFGAI_2GameModeBase;
class UGridNode;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FGAI_2_API UAStar : public UActorComponent
{
	GENERATED_BODY()
public:	
	UAStar();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* StartActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* EndActor;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Start;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector End;

	FVector Velocity;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool Move = false;
	TArray<FGridNode*> path;
	UPROPERTY(EditAnywhere)
	AMyGrid* grid = nullptr;

	UPROPERTY(EditAnywhere)
	AFGAI_2GameModeBase* Instance = nullptr;

	UPROPERTY(EditAnywhere)
	bool jumpPoint = true;

	UPROPERTY(EditAnywhere)
	FColor Color = FColor::Red;

	FVector2D Direction;
	int TargetIndex;
	
protected:
	virtual void BeginPlay() override;

public:
	void PathFailed();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void FindPath(FVector startPos, FVector targetPos);
	void RetracePath(FGridNode* startNode, FGridNode* endNode);
	int GetDistance(FGridNode* nodeA, FGridNode* nodeB);

	TArray<FGridNode*> SearchDirection(TArray<FGridNode*> SearchPath);
};
