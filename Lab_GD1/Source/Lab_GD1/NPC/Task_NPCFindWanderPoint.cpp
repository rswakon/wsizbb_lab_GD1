

#include "Task_NPCFindWanderPoint.h"
#include "Classes/Kismet/GameplayStatics.h"
#include "Classes/BehaviorTree/BehaviorTreeComponent.h"
#include "Classes/BehaviorTree/BlackboardComponent.h"
#include "NPCAIController.h"
#include "NPCTargetPoint.h"

static FName NAME_WanderPointKey("WanderPoint");

EBTNodeResult::Type UTask_NPCFindWanderPoint::ExecuteTask(class UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ANPCAIController* AIController = Cast<ANPCAIController>(OwnerComp.GetAIOwner());
	UBlackboardComponent* AIBlackboard = AIController->GetBlackboardComp();

	if (!AIController || !AIBlackboard)
	{
		return EBTNodeResult::Failed;
	}

	TArray<AActor*> WanderPoints;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ANPCTargetPoint::StaticClass(), WanderPoints);

	if (WanderPoints.Num() == 0)
		return EBTNodeResult::Failed;

	ANPCTargetPoint* CurrentWanderPoint = Cast<ANPCTargetPoint>(AIBlackboard->GetValueAsObject(NAME_WanderPointKey));
	ANPCTargetPoint* NewWanderPoint = Cast<ANPCTargetPoint>(WanderPoints[FMath::RandRange(0, WanderPoints.Num() - 1)]);
	if (WanderPoints.Num() == 1)
	{

		AIBlackboard->SetValueAsObject(NAME_WanderPointKey, NewWanderPoint);
		return EBTNodeResult::Succeeded;

	}
	while (NewWanderPoint == CurrentWanderPoint)
	{
		NewWanderPoint = Cast<ANPCTargetPoint>(WanderPoints[FMath::RandRange(0, WanderPoints.Num() - 1)]);
	}

	AIBlackboard->SetValueAsObject(NAME_WanderPointKey, NewWanderPoint);
	return EBTNodeResult::Succeeded;

}
