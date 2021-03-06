// Copyright Panayiotis Philippou 2017.

#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_API UGrabber : public UActorComponent
{
	GENERATED_BODY()
public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:
		// How far ahead of the player can we reach,How long are the hands	
	float Reach = 100.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;

	//Ray-cast and grab staff
	void Grab();

	//release staff when key is released
	void Release();

	//find attached physics handle 
	void FindPhysicsHandleComponent();

	// Setup assumed attached input component
	void SetupInputComponent();

	// Reeturns hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();
	
	// Returns current start of reacj line
	FVector GetReachLineStart();

	// Returns current end of reacj line
	FVector GetReachLineEnd();
};
