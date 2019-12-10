// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame(); // Setting up Game

    PrintLine(TEXT("The HiddenWord is: %s"), *HiddenWord); // Debug line

    // Welcoming the Player
    PrintLine(TEXT("Welcome to Bull + Cows!"));
    PrintLine(TEXT("Guess the %i letter word."), HiddenWord.Len()); // Magic number remove!
    PrintLine(TEXT("Press Tab to begin, enter something!"));
    
    // Prompt player for guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    // Checking the player guess

    if ( Input == HiddenWord ) {
        PrintLine("That is the hidden word, you won!");
    } else {
        if (Input.Len() != HiddenWord.Len()) {
            PrintLine(TEXT("The hidden word is %i letters long!"), HiddenWord.Len());
        } else {

        }
    }

    // Check if Isogram
    // Prompt to guess again
    // Check Right Number of Characters
    // Prompt to guess again

    // Remove Life

    // Check If Lives > 0

    // If Yes, guess again
    // Show lives left
    // Else, show game over and hidden word
    // Prompt play again, Press enter to play again
    // Check user input 
    // Play again or quit
}

void UBullCowCartridge::SetupGame() 
{
    HiddenWord = TEXT("cake");
	Lives = 4;
}