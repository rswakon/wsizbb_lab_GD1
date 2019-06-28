// Fill out your copyright notice in the Description page of Project Settings.


#include "Task_GetNextRandomPoint.h"
#include "AI/NavigationSystemBase.h"
#include "NavigationSystem.h"
#include "AbstractNavData.h"

#include "NPCAIController.h"
#include "Classes/BehaviorTree/BlackboardComponent.h"
static FName NAME_RandomPointKey("RandomPoint");
EBTNodeResult::Type UTask_GetNextRandomPoint::ExecuteTask(class UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ANPCAIController* AIController = Cast<ANPCAIController>(OwnerComp.GetAIOwner());
	UBlackboardComponent* AIBlackboard = AIController->GetBlackboardComp();
	if(!AIController || !AIBlackboard)
		return EBTNodeResult::Failed;

	FVector Origin = AIController->K2_GetActorLocation();
	FVector RandomPoint;
	float Radius = 1000.0f;

	UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());

	if (NavSys->K2_GetRandomPointInNavigableRadius(GetWorld(), Origin, RandomPoint, Radius))
	{
		AIBlackboard->SetValueAsVector(NAME_RandomPointKey, RandomPoint);
		return EBTNodeResult::Succeeded;
	}
	else
		return EBTNodeResult::Failed;

}
