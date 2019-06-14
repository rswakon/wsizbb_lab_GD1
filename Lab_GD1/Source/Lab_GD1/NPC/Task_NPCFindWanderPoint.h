
#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Task_NPCFindWanderPoint.generated.h"

/**
 * 
 */
UCLASS()
class LAB_GD1_API UTask_NPCFindWanderPoint : public UBTTaskNode
{
	GENERATED_BODY()
	
		virtual EBTNodeResult::Type ExecuteTask(class UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	
};
