// Fill out your copyright notice in the Description page of Project Settings.

#include "NPCAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "Runtime/AIModule/Classes/Perception/PawnSensingComponent.h"
#include "NPCChar.h"

ANPCAIController::ANPCAIController() {
	//PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComponent"));
	BTComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComponent"));
	BBComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
}

void ANPCAIController::OnPossess(APawn *myPawn) {
	Super::OnPossess(myPawn);

	ANPCChar *NPC = Cast<ANPCChar>(myPawn);

	if (NPC && NPC->NPCBT) {
		BBComp->InitializeBlackboard(*NPC->NPCBT->BlackboardAsset);

		NPCKeyID = BBComp->GetKeyID("PlayerPosition");

		BTComp->StartTree(*NPC->NPCBT);

	}

}
