// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BP_LightSwitch_CPP.generated.h"

UCLASS()
class WHATEVS_API ABP_LightSwitch_CPP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABP_LightSwitch_CPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//point light component
	UPROPERTY(VisibleAnywhere, Category = "Components")
		class UPointLightComponent* PointLight;

	UPROPERTY(VIsibleAnywhere, Category = "Components")
		class USphereComponent* Sphere;

	// called when something overlaps the sphere component
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp,
		class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
		int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// called when something ends overlapping the sphere component
	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp,
		class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
		int OtherBodyIndex);

	UFUNCTION()
		void ToggleLight();

	UPROPERTY(VisibleAnywhere, Category = "Components")
		float DesiredIntensity;
};
