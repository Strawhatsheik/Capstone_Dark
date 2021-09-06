// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StoryUserWidget.h"
#include "MainGameMode.h"
#include "Room.h"
#include "Engine/LevelScriptActor.h"
#include "LevelScriptActor_Room.generated.h"

/**
 * 
 */
UCLASS()
class DARK_API ALevelScriptActor_Room : public ALevelScriptActor
{
	GENERATED_BODY()



	//So maybe a funciton to laod level here? ike the room actor?
	//On beginging of game play  (called by begin play in Blueprint0		
	UFUNCTION(BlueprintCallable, Category = LevelBlueprint)
		void LevelSetup();
	
protected:

	//Class variables

	//All levels have a begining description
	FString MainDescription;
	
public:

	//Array with level names
//	UPROPERTY()
		//TArray<FString> LevelNames;
	//ARoom* ANewRoom;
};
