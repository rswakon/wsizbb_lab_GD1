// Fill out your copyright notice in the Description page of Project Settings.

#include "NPCChar.h"
#include "Perception/PawnSensingComponent.h"
#include "NPCAIController.h"
#include "GameFramework/Actor.h"
#include "Lab_GD1Character.h"
#include "Engine/World.h"
// Sets default values
ANPCChar::ANPCChar()
{

	/* Our sensing component to detect players by visibility and noise checks. */
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
	PawnSensingComp->SetPeripheralVisionAngle(60.0f);
	PawnSensingComp->SightRadius = 2000;
	PawnSensingComp->HearingThreshold = 600;
	PawnSensingComp->LOSHearingThreshold = 1200;
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SenseTimeOut = 2.5f;
	LastSeenTime = 0.f;

}

// Called when the game starts or when spawned
void ANPCChar::BeginPlay()
{
	Super::BeginPlay();
	if (PawnSensingComp)
	{
		PawnSensingComp->OnSeePawn.AddDynamic(this, &ANPCChar::OnSeePlayer);
	
	}
	
}

// Called every frame
void ANPCChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UWorld* World = GetWorld();
	if  (World &&( World->GetTimeSeconds() - LastSeenTime) > SenseTimeOut)
	{
		ANPCAIController* AIController = Cast<ANPCAIController>(GetController());
		if (AIController)
		{
			AIController->SetShouldWander(true);
			/* Reset */
			AIController->SetTargetEnemy(nullptr);

	
		}
	}

}

void ANPCChar::OnSeePlayer(APawn* SensedPawn)
{
	
	UWorld* World = GetWorld();
	if (!World)
		return;
	LastSeenTime = World->GetTimeSeconds();
	 

	ANPCAIController* AIController = Cast<ANPCAIController>(GetController());
	if (AIController)
	{
		AIController->SetShouldWander(false);
		AIController->SetTargetEnemy(SensedPawn);
	}
	 
}



