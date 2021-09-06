// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InventoryItem.generated.h"

UCLASS()
class DARK_API AInventoryItem : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	// constructor
	AInventoryItem();

	//Overloaded constructor
	//Each level will instanstiate their items. They will pass in whether in items is usable (bool), it's name (string),
	//and it's description. 
	//Maybe also take a voive element for description? 
	AInventoryItem(bool ItemActive, FString ItemsName, FString ItemsDescription);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

//private:
	//Class properties
	//To hold the items name
	UPROPERTY(BlueprintReadWrite)
		FString ItemName;
	//To hold the items description
	UPROPERTY(BlueprintReadWrite)
		FString ItemDescription;
	//To hold whether the item can be used
	UPROPERTY(BlueprintReadWrite)
		bool ItemEnabled;

};