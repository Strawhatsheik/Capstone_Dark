// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"//To include use of buttons
#include "StoryUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class DARK_API UStoryUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	//Class properties
	//Create main text block and bind to widget
	//UPROPERTY(meta =(BindWidget))
		//class UTextBlock* MainText;
	
	//Buttons on Widget 
	//Create 'sight' button and bind to widget
	UPROPERTY(meta = (BindWidget))
		class UButton* LookButton;
	//Create 'listen' button and bind to widget
	UPROPERTY(meta = (BindWidget))
		class UButton* ListenButton;
	//Create 'touch' button and bind to widget
	UPROPERTY(meta = (BindWidget))
		class UButton* TouchButton;
	//Create 'taste' button and bind to widget
	UPROPERTY(meta = (BindWidget))
		class UButton* TasteButton;
	//Create 'smell' button and bind to widget
	UPROPERTY(meta = (BindWidget))
		class UButton* SmellButton;
	//Create 'move' button and bind to widget
	UPROPERTY(meta = (BindWidget))
		class UButton* MoveButton;
	//Create 'save' button and bind to widget
	UPROPERTY(meta = (BindWidget))
		class UButton* SaveButton;
	//Create 'exit' button and bind to widget
	UPROPERTY(meta = (BindWidget))
		class UButton* ExitButton;
	//Create 'stats' button and bind to widget
	UPROPERTY(meta = (BindWidget))
		class UButton* StatsButton;
	//
//UButton* myBtn;
//myBtn->OnClicked.AddDynamic(this, &UMyUObjectClass::MyUFunctionOnClickMethod);
// 
	//From tutorial
	bool Initialize() override;


public:
	//Class functions
	//For constructor
	//Part of parent user class
	void NativeConstruct() override;

	//void OnGenerateButtonClicked();
	
	//Variables
	//moving here, maybe theyll work???
	//FString LookButtonTxt = "Look button pressed";
//	FString ListenButtonTxt = "Listen button pressed";
	
	//To keep track of room events until roomn class created:
	bool PhoneEnabled = false;
	bool WatchEnabled = false;
	bool LevelTwoEnabled = false;
	//Counters to aid in keeping track of button presses until room class made???

	// Button functions
	//Function to handle when 'look' button is clicked
	UFUNCTION(BlueprintCallable, Category = "Button pressed")
		void LookButtonPressed();

	// Function to handle when 'Listen' button is pressed
	UFUNCTION(BlueprintCallable, Category = "Button pressed")
		void ListenButtonPressed();

	// Function to handle when 'touch' button is pressed
	UFUNCTION(BlueprintCallable, Category = "Button pressed")
		void TouchButtonPressed();

	// Function to handle when 'taste' button is pressed
	UFUNCTION(BlueprintCallable, Category = "Button pressed")
		void TasteButtonPressed();

	// Function to handle when 'smell' button is pressed
	UFUNCTION(BlueprintCallable, Category = "Button pressed")
		void SmellButtonPressed();


	// Function to handle when 'Move' button is pressed
	UFUNCTION(BlueprintCallable, Category = "Button pressed")
		void MoveButtonPressed();

	// Function to handle when 'save' button is pressed
	UFUNCTION(BlueprintCallable, Category = "Button pressed")
		void SaveButtonPressed();

	// Function to handle when 'exit' button is pressed
	UFUNCTION(BlueprintCallable, Category = "Button pressed")
		void ExitButtonPressed();
	
	// Function to handle when 'STATS' button is pressed
	UFUNCTION(BlueprintCallable, Category = "Button pressed")
		void StatsButtonPressed();

	// Function to update maintext box
	UFUNCTION(BlueprintCallable, Category = "Button pressed")
		void UpdateMain(FString NewMain);

	//Speech mapping?
	/*
	FInputActionSpeechMapping
	(
		const FName SaveGame;
	const FName Save;
	) */


private:
	//from tutorial
	//UPROPERTY(meta = (BindWidget))//We are going to 'forward'declare a pointer to target a specific item in blueprint widget
		//class UTextBlock*ScoreText
		//The asterisk is the pointer (in tutorial he puts       ScoreText, but I will put MainText
		
	//Create main text block and bind to widget
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* MainText;

	//Tutorial, but could be named dif!!!
	//UFUNCTION()
		//FText SetScoreField();


};
