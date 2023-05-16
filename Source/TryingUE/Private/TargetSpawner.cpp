// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetSpawner.h"
#include "../TryingUEProjectile.h"

// Sets default values
ATargetSpawner::ATargetSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATargetSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATargetSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UWorld* const World = GetWorld();
	m_timer += DeltaTime;
	if (World != nullptr && m_timer > 2.0f && m_box != nullptr)
	{
		//APlayerController* PlayerController = Cast<APlayerController>(Character->GetController());
		const FRotator SpawnRotation = GetActorRotation();
		// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
		const FVector SpawnLocation = GetActorLocation();

		//Set Spawn Collision Handling Override
		/*FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;*/

		// Spawn the projectile at the muzzle
		World->SpawnActor<ATryingUEProjectile>(m_box, SpawnLocation, SpawnRotation);

		m_timer = 0.0f;
	}
}

