// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryItem.h"

// Sets default values
AInventoryItem::AInventoryItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//default parameters
	ItemName = " ";
	ItemDescription = " ";
	ItemEnabled = false;

}

// Sets default values for overloaded constructor
AInventoryItem::AInventoryItem(bool ItemActive, FString ItemsName, FString ItemsDescription)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//takes parameters and assigns to this instance of an inventory item
	ItemName = ItemsName;
	ItemDescription = ItemsDescription;
	ItemEnabled = ItemActive;
}

// Called when the game starts or when spawned
void AInventoryItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInventoryItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

