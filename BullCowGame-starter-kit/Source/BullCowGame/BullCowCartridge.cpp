// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame(); // Setting up Game

    // PrintLine(TEXT("The HiddenWord is: %s"), *HiddenWord); // Debug line
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (bGameOver) 
    {
        ClearScreen();
        SetupGame();
    }
    else 
    {
        ProcessGuess(Input);
        
    }
}

void UBullCowCartridge::SetupGame() 
{
    PrintLine(TEXT("Welcome to Bull + Cows!"));
    HiddenWord = TEXT("cakes");
	Lives = 4;
    bGameOver = false;
    // Welcoming the Player
    PrintLine(TEXT("Guess the %i letter word."), HiddenWord.Len()); // Magic number remove!
    // Prompt player for guess
    PrintLine(TEXT("Type in your guess...\nPress enter to continue."));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine("Press enter to play again.");
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if ( Guess == HiddenWord ) 
    {
        PrintLine("You have won!");
        EndGame();
    } 
    else 
    {
        PrintLine(TEXT("You lost a life!"));
        --Lives;
        if (Lives <= 0) 
        {
            ClearScreen();
            PrintLine(TEXT("You have no lives left!"));
            PrintLine(TEXT("The hidden word was %s."), *HiddenWord);
            EndGame();
        }
        else
        {
            IsIsogram(Guess);
            PrintLine(TEXT("Try guessing again.\nYou have %i lives remaining."), Lives);

        }
    }
    
}

void UBullCowCartridge::IsIsogram(FString Word)
{
    if (Word.Len() != HiddenWord.Len()) 
    {
        PrintLine("There are no repeating letters.");
        PrintLine(TEXT("The hidden word is %i characters long."), HiddenWord.Len());
    }
    else
    {
        int32 bulls = 0;
        int32 cows = 0;

        // Bull check
        for ( int32 i = 0; i < Word.Len(); i++ )
        {
            if (Word[i] == HiddenWord[i])
            {
                bulls++;
            }

            FString remainingLetters;

            for ( int32 j = i; j < HiddenWord.Len(); j++)
            {
                remainingLetters.AppendChar(HiddenWord[j]);
            }

            if (remainingLetters.Contains(&Word[i]))
            {
                cows++;
            }
        }

        if ( bulls > 0)
        {
            PrintLine(TEXT("You have %i bulls."), bulls);
        }

        if ( cows > 0 )
        {
            PrintLine(TEXT("You have %i cows."), cows);
        }
    }
}
