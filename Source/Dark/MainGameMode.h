// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class DARK_API AMainGameMode : public AGameModeBase
{
	GENERATED_BODY()

		//Default constructor
		AMainGameMode();

	//Maybe the variables go in game mode, not room? Just need enough for POC???

	//From tutorial
	//This function sets the points, and is callable, maybe health can be in gamemode???
	UFUNCTION(BlueprintCallable)
		void SetMainText(FString value);
	//This is a retreiver function
	UFUNCTION(BlueprintCallable)
		FString GetMainText();

private:
	//From tutorial
	//Here is the property of the score, could be used for player health?????
	UPROPERTY()
		int32 Score;

public:
	//Variable of main text to move from level to widget
	UPROPERTY(BlueprintReadWrite)
		FString TextForBox;

};
