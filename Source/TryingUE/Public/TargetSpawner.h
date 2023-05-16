// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetSpawner.generated.h"

class ATryingUEProjectile;

UCLASS()
class TRYINGUE_API ATargetSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATargetSpawner();

	UPROPERTY(EditDefaultsOnly, Category = Gameplay)
	TSubclassOf<class ATryingUEProjectile> m_box;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(VisibleAnywhere, Category = Gameplay)
	float m_timer = 0.0f;
};
