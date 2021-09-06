// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Misc/FileHelper.h" //To enable loading files

#include "Room.generated.h"

UCLASS()
class DARK_API ARoom : public AActor
{
	GENERATED_BODY()
		//Rooms need to control their puzzles and their items
			//So they need to instantiate their items and instantiate their puzzles
		//They also neeed to control their descriptions and auido 
			//These need to be in constructor
				//Or do they because didn't we decide that the call delegates would have? Seems sloppy though

public:	
	// Sets default values for this actor's properties
	ARoom();

	//Overloaded constructor
	// 	   //Maybe the constructor takes a filname as param, to load in each level the diff descriptions? but while clever will that save time since audio must also be loaded into each level? 
	// 	   //What about audio path file names? That is txt right...hrmmm
	// 	   //IF that works than each could eb a level per CSV file? 
	ARoom(FString LevelFile );
	//Variables

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Function to load level descriptions and events
	UFUNCTION(BlueprintCallable)
		void LoadLevel(FString LevelFile);
	
	//Functions to pass info/descriptions to widgets
	//Pass 'look' info
	UFUNCTION(BlueprintCallable)
		FString GetLookDescription();
	//Pass 'listen' info
	UFUNCTION(BlueprintCallable)
		FString GetListenDescription();
	//Pass 'taste' info
	UFUNCTION(BlueprintCallable)
		FString GetTasteDescription();
	//Pass 'touch' info
	UFUNCTION(BlueprintCallable)
		FString GetTouchDescription();
	//Pass 'move' info
	UFUNCTION(BlueprintCallable)
		FString GetMoveDescription();
	//Pass 'smell' info
	UFUNCTION(BlueprintCallable)
		FString GetSmellDescription();
	
	//Functions to change CURRENT info/descriptions that will be passed to widgets
	//Set 'look' info
	UFUNCTION(BlueprintCallable)
		void SetSightDescription(FString NewCurrent);
	//Set 'listen' info
	UFUNCTION(BlueprintCallable)
		void SetListenDescription(FString NewCurrent);
	//Set 'taste' info
	UFUNCTION(BlueprintCallable)
		void SetTasteDescription(FString NewCurrent);
	//Set 'touch' info
	UFUNCTION(BlueprintCallable)
		void SetTouchDescription(FString NewCurrent);
	//Set 'move' info
	UFUNCTION(BlueprintCallable)
		void SetMoveDescription(FString NewCurrent);
	//Set 'smell' info
	UFUNCTION(BlueprintCallable)
		void SetSmellDescription(FString NewCurrent);
	
	//Variables to hold the CURRENT description, what is passed to calling arguments
	UPROPERTY(BlueprintReadWrite, Category = "Current Description")
		FString CurrentLook;
	UPROPERTY(BlueprintReadWrite, Category = "Current Description")
		FString CurrentListen;
	UPROPERTY(BlueprintReadWrite, Category = "Current Description")
		FString CurrentTaste;
	UPROPERTY(BlueprintReadWrite, Category = "Current Description")
		FString CurrentSmell;
	UPROPERTY(BlueprintReadWrite, Category = "Current Description")
		FString CurrentTouch;
	UPROPERTY(BlueprintReadWrite, Category = "Current Description")
		FString CurrentMove;
	//Variables to hold descriptions, the multiple numbers reflect multiple paths available
	//If  there is no multiple path in level it is null
	//The opening description for level
	UPROPERTY(BlueprintReadWrite, Category = "Look Description")
		FString OpeningDesc;
	//The LOOK properties
	UPROPERTY(BlueprintReadWrite, Category = "Look Description")
		FString Look1;
	UPROPERTY(BlueprintReadWrite, Category = "Look Description")
	    FString Look2;
	UPROPERTY(BlueprintReadWrite, Category = "Look Description")
		FString Look3;
	//The LISTEN properties
	UPROPERTY(BlueprintReadWrite, Category = "Listen Description")
		FString Listen1;
	UPROPERTY(BlueprintReadWrite, Category = "Listen Description")
		FString Listen2;
	UPROPERTY(BlueprintReadWrite, Category = "Listen Description")
		FString Listen3;
	//The TASTE properties
	UPROPERTY(BlueprintReadWrite, Category = "Taste Description")
		FString Taste1;
	UPROPERTY(BlueprintReadWrite, Category = "Taste Description")
		FString Taste2;
	UPROPERTY(BlueprintReadWrite, Category = "Taste Description")
		FString Taste3;
	//The TOUCH properties
	UPROPERTY(BlueprintReadWrite, Category = "Touch Description")
		FString Touch1;
	UPROPERTY(BlueprintReadWrite, Category = "Touch Description")
		FString Touch2;
	UPROPERTY(BlueprintReadWrite, Category = "Touch Description")
		FString Touch3;
	//The SMELL properties
	UPROPERTY(BlueprintReadWrite, Category = "Smell Description")
		FString Smell1;
	UPROPERTY(BlueprintReadWrite, Category = "Smell Description")
		FString Smell2;
	UPROPERTY(BlueprintReadWrite, Category = "Smell Description")
		FString Smell3;
	//The MOVE properties
	UPROPERTY(BlueprintReadWrite, Category = "Move Description")
		FString Move1;
	UPROPERTY(BlueprintReadWrite, Category = "Move Description")
		FString Move2;
	UPROPERTY(BlueprintReadWrite, Category = "Move  Description")
		FString Move3;

	//Function to turn CSV into array
	//I think  this must be IN a function, not just alone

	//static bool FFileHelper::LoadFileToStringArray(TArray<FString>& LevelStuff, const TCHAR * "LevelTest1.txt");

	//What it needs are items to pass INTO it
	TArray<FString> LevelInfo;


};
//
/**
	 * Load a text file to an array of strings. Supports all combination of ANSI/Unicode files and platforms.
	 *
	 * @param Result       String representation of the loaded file
	 * @param Filename     Name of the file to load
	 
static bool LoadFileToStringArray(TArray<FString>& Result, const TCHAR* Filename); */