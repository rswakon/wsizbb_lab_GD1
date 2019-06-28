// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Task_GetNextRandomPoint.generated.h"

/**
 * 
 */
UCLASS()
class LAB_GD1_API UTask_GetNextRandomPoint : public UBTTaskNode
{
	GENERATED_BODY()
		virtual EBTNodeResult::Type ExecuteTask(class UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	
};
