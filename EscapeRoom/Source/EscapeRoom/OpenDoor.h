// Copyright Panayiotis Philippou 2017.

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:
	UPROPERTY(VisibleAnywhere)  //VisibleAnywhere if we dont want to be editable
	float SetTheOpenValue = 90.f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate; //Set a trigger, Unreal we autocomplete.

	AActor* ActorThatOpens;

	
};