// Fill out your copyright notice in the Description page of Project Settings.

#include "NPCAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Lab_GD1Character.h"

#include "NPCChar.h"



ANPCAIController::ANPCAIController() {
	BTComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComponent"));
	BBComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
	TargetEnemyKeyName = "TargetEnemy";
	ShouldWanderKeyName = "ShouldWander";

}

void ANPCAIController::OnPossess(APawn *myPawn) {
	Super::OnPossess(myPawn);

	ANPCChar *NPC = Cast<ANPCChar>(myPawn);

	if (NPC && NPC->NPCBT) {
		BBComp->InitializeBlackboard(*NPC->NPCBT->BlackboardAsset);
		BTComp->StartTree(*NPC->NPCBT);

	}

}




void ANPCAIController::SetTargetEnemy(APawn* NewTarget)
{
	if (BBComp)
	{
		BBComp->SetValueAsObject(TargetEnemyKeyName, NewTarget);
	}
}

 void ANPCAIController::SetShouldWander(bool ShouldWander)
 {
	 if (BBComp)
	 {
		 BBComp->SetValueAsBool(ShouldWanderKeyName, ShouldWander);
	 }
 
 }

APawn* ANPCAIController::GetTargetEnemy()
{
	if (BBComp)
	{
		return Cast<APawn>( BBComp->GetValueAsObject(TargetEnemyKeyName));
	}

	return nullptr;
}
