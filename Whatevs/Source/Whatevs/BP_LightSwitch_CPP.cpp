// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/PointLightComponent.h"
#include "Components/SphereComponent.h"
#include "BP_LightSwitch_CPP.h"

// Sets default values
ABP_LightSwitch_CPP::ABP_LightSwitch_CPP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	DesiredIntensity = 300000.f;
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));
	PointLight->Intensity = DesiredIntensity;
	RootComponent = PointLight;
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->InitSphereRadius(250.0f);
	Sphere->SetupAttachment(RootComponent);
	// assign delegates
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ABP_LightSwitch_CPP::OnOverlapBegin);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ABP_LightSwitch_CPP::OnOverlapEnd);
}
// Called when the game starts or when spawned
void ABP_LightSwitch_CPP::BeginPlay()
{
	Super::BeginPlay();
	
}
// Called every frame
void ABP_LightSwitch_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABP_LightSwitch_CPP::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp) {
		ToggleLight();
	}
}

void ABP_LightSwitch_CPP::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp) {
		ToggleLight();
	}
}

void ABP_LightSwitch_CPP::ToggleLight()
{
	PointLight->ToggleVisibility();
}

