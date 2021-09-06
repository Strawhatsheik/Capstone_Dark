// Fill out your copyright notice in the Description page of Project Settings.


#include "StoryUserWidget.h"
#include "MainGameMode.h"
#include "Room.h"
#include "Components/TextBlock.h"//To enable use of textblock


//How to keep track of room sinc these aren't technically levels? Soemthing like boolean Character In? 
// //If levels wrote back to teir files that would enable saving, but what about originals Maybe NEwgame->copy over
//OR would it be better to actually make levels in unreal annnnnnnnnndfsd  maybe if we use ULEvle instead of actor object and 
//stream the different levels it would accomplish!!!
//Maybe make multiple levels in Unreal and hav e them load reg, but only have each level call its own level actor
//Then player actor can interact with?? ?
//Maybe each level can have  amount of functions but if the array loaded is blank they can have 
//a boolean nulling them. Or maybe each one will require personal tweaking, tyhis isnt a randomized game
//the ones with base stuff like decript still works

//From tutorial
bool UStoryUserWidget::Initialize()
{
	bool Success = Super::Initialize(); //call base class initialize (Super calls bas eclass thingy!
	
	//Found online example of calling and cating
		//AClass1* actorClass = Cast<AClass1>(GetWorld()->SpawnActor(AClass1::StaticClass())));
		// or shorter: AClass1* actorClass = GetWorld()->SpawnActor<AClass1>();

		//actorClass->SpecialFunction();
	

	//If not success return flase
	if (!Success) return false;

	//Check scoreText is valid field (I'll change to Main casue thats MINE
	if (MainText)
	{
		UE_LOG(LogTemp, Warning, TEXT("Main text Found"))
	
			//Retreive world, there is a way in parent class!
			//Get world and POINT it to a world type with ref name GetWOrld (Look Im learning)
			UWorld* World = GetWorld();

		//If the world is retrieved successfully, IE not null
		if (World != nullptr)
		{
			//Cast to gameMode
			AMainGameMode* MainGameMode = Cast<AMainGameMode>(World->GetAuthGameMode());

			if (MainGameMode) {
				//debugger
				UE_LOG(LogTemp, Warning, TEXT("Main gamemode Found"))
			}
			//Tutorial had scoreText, I made maintext
			MainText->SetText(FText::FromString("You wake up to confusion. You have a splitting headache. A dull thud-thud as you feel each beat of your heart behind your ears. It's dark, terribly dark. In your drowsy state you think your eyes are shut, but by blinking you realize they're not. The darkness is absolute. It is total and complete, the pure absence of anything. You are not sure where you are or how you got here. All you know for sure is it is dark, your head hurts, and your scared."));

			//set delegate (which is same thing as "bind, and creating bind in Blueprint!!) //accessing from C++!!!
			//Object we are binding it to is maintext, ie this and see the method below! That was declare din .h file
			MainText->TextDelegate.BindUFunction(this, "SetScoreField");

		}
	
	}

	//From tutorial
	return true;
}

//Constructor
void UStoryUserWidget::NativeConstruct()
{
	//Call constructor for widget.
	Super::NativeConstruct();

	//Bind button handling functions ot delegates
	//When button is clicked, call 'on clicked delegate' on the LOOK button in this widget
	LookButton->OnClicked.AddUniqueDynamic(this, &UStoryUserWidget::LookButtonPressed);

	//When button is clicked, call 'on clicked delegate' on the LISTEN button in this widget
	ListenButton->OnClicked.AddUniqueDynamic(this, &UStoryUserWidget::ListenButtonPressed);

	//When button is clicked, call 'on clicked delegate' on the TOUCH button in this widget
	TouchButton->OnClicked.AddUniqueDynamic(this, &UStoryUserWidget::TouchButtonPressed);

	//When button is clicked, call 'on clicked delegate' on the TASTE button in this widget
	TasteButton->OnClicked.AddUniqueDynamic(this, &UStoryUserWidget::TasteButtonPressed);

	//When button is clicked, call 'on clicked delegate' on the SMELL button in this widget
	SmellButton->OnClicked.AddUniqueDynamic(this, &UStoryUserWidget::SmellButtonPressed);

	//When button is clicked, call 'on clicked delegate' on the MOVE button in this widget
	MoveButton->OnClicked.AddUniqueDynamic(this, &UStoryUserWidget::MoveButtonPressed);

	//When button is clicked, call 'on clicked delegate' on the SAVE button in this widget
	SaveButton->OnClicked.AddUniqueDynamic(this, &UStoryUserWidget::SaveButtonPressed);

	//When button is clicked, call 'on clicked delegate' on the LISTEN button in this widget
	ExitButton->OnClicked.AddUniqueDynamic(this, &UStoryUserWidget::ExitButtonPressed);

	//When button is clicked, call 'on clicked delegate' on the STATS button in this widget
	StatsButton->OnClicked.AddUniqueDynamic(this, &UStoryUserWidget::StatsButtonPressed);
}
//This is how you assign a DELEGATE function The reason my functions weren't working is I am not call
// THEM I am calling a delegate, whoi can thebn call them if I want him to. To be assigned to delegate a function must be a ufunction
// I'm getting close I canm feel it
// ALSO!! The reason that the deleagte said "ongenerateclicked" was not because it genereated clicked, that was THE NAME OF DELEGATE
// So I put my names in there
// I could also have one delegeat 'onclicked' and have it sort which button was clicked by if statem,ent and then call appropriate function.
// I wonder whats better?
//myBtn->OnClicked.AddDynamic(this, &UMyUObjectClass::MyUFunctionOnClickMethod);
// 
//Also I think the delegates are good becaus ethey can be called by each level and do something different in each one. Levels handle counters as well? IE how
//many times button is pressed. 

//Function when button clicked
/*void UStoryUserWidget::OnGenerateButtonClicked()
{

}*/

//Function definitions

//For delegate funtion, on clicked event
void UStoryUserWidget::LookButtonPressed()
{
	if (PhoneEnabled)
	{
		MainText->SetText(FText::FromString("Cautiously you swing your phone around and survey your surroundings. The phones light brings some comfort, but not what it reveals. You see a large pile of rubble and realize this is where you fell in. You remember now, the low stomach swoop as the ground gave way. The pile extends up to the ceiling. The only way out of the room appears to be a small opening under a jagged overhang to your right."));
		LevelTwoEnabled = true;
	}
	else
	{
		if (WatchEnabled)
		{
			MainText->SetText(FText::FromString("The little light from your watch is comforting, but not strong. You use it to try and take stock, but it barely cuts the darkness. You crawl around holding it in front of you and find what you were looking for. Your phone, which had been in your back pocket! You grab it and swipe to turn it on. The screen is badly cracked but usable. Your heart sinks when you see there is no signal. You can at least have a stronger light though! You turn on your phone’s flashlight app and a brilliant white beam cuts the darkness."));
			WatchEnabled = false;
			PhoneEnabled = true;
		}
		else
		{
			MainText->SetText(FText::FromString("You can’t see anything at all. You blink and rub your eyes, but while the action is comforting, it yields no results. You are still in darkness."));

		}
	}

}

void UStoryUserWidget::ListenButtonPressed()
{
	MainText->SetText(FText::FromString("You hear nothing. Absolutely nothing except the sound of your own breathing."));
	
}
//For delegate funtion, on clicked event
void UStoryUserWidget::TouchButtonPressed()
{
	MainText->SetText(FText::FromString("You feel around frantically, under her hands seems to be cold stone and something gritty, possibly dirt? You reach above your head stretching and as you do your electronic watch lights up revealing the time and date. You are initially blinded even the small glow from it, but are desperate to keep it on. You access it's flashlight function. The screen lights up a little brighter. You always found the light of this function to dim to do any good and ridiculed it. Now you feel like you could kiss it!"));
	//Enable FOUND WATCH
	WatchEnabled = true;
	//return LookButtonTxt;
}

//For delegate funtion, on clicked event
void UStoryUserWidget::SmellButtonPressed()
{
	MainText->SetText(FText::FromString("Your throat is constricted, and breathing is difficult from all the dust in the air."));

}

//For delegate funtion, on clicked event
void UStoryUserWidget::TasteButtonPressed()
{
	MainText->SetText(FText::FromString("You cough as you try to swallow and realize how incredibly dry your mouth is. It also feels gritty, like you swallowed dirt. You are desperate for a drink."));
	//return LookButtonTxt;
}

//For delegate funtion, on clicked event
void UStoryUserWidget::MoveButtonPressed()
{
	//If phoneenabled is FALSE 
	if (!PhoneEnabled) {
		MainText->SetText(FText::FromString("You can't move if you can't see where you are going! You are afraid to hurt yourself!"));
	}
	else {
		//if phoneenabled is TRUE
		MainText->SetText(FText::FromString("You only have one option, so you head toward it. The overhang. The gap under it is small, you have to crawl through on your belly. It is very claustrophobic, but a preliminary glance with the flashlight seems to show a large room beyond, so you wiggle through."));
	}
}

//For delegate funtion, on clicked event
void UStoryUserWidget::SaveButtonPressed()
{
	MainText->SetText(FText::FromString("Save button clicked"));
	//return LookButtonTxt;
}

//For delegate funtion, on clicked event
void UStoryUserWidget::ExitButtonPressed()
{
	MainText->SetText(FText::FromString("Exit button clicked"));
	//return LookButtonTxt;
}

//For delegate funtion, on clicked event
void UStoryUserWidget:: StatsButtonPressed()
{
	MainText->SetText(FText::FromString("Stats button clicked"));
	//return LookButtonTxt;
}
void UStoryUserWidget::UpdateMain(FString NewMain)
{
	MainText->SetText(FText::FromString(NewMain));
}


//
//UButton* myBtn;
//myBtn->OnClicked.AddDynamic(this, &UMyUObjectClass::MyUFunctionOnClickMethod);

/*
FText UStoryUserWidget::SetScoreField()
{

	//Get world and POINT it to a world type with ref name GetWOrld (Look Im learning)
	UWorld* World = GetWorld();

	//If the world is retrieved successfully, IE not null
	if (World != nullptr)
	{
		//Cast to gameMode
		AMainGameMode* MainGameMode = Cast<AMainGameMode>(World->GetAuthGameMode());

		if (MainGameMode) {
			//debugger
			UE_LOG(LogTemp, Warning, TEXT("Main gamemode Found"))
		}
	return FText();
}*/
