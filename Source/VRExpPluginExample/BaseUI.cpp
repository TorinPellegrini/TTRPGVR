// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseUI.h"


//Takes in player's attributes and fills the text in on the UI
void UBaseUI::FillGeneralAttributes(UAttributesComponent* PlayerAttributes, FText CharacterName, FText PlayerMovementSpeed)
{
	PlayerHealth->SetText(GetTextFromAttributeValue(PlayerAttributes->GetHealthAttribute().CurrentValue));;
	MaxHP->SetText(GetTextFromAttributeValue(PlayerAttributes->GetHealthAttribute().MaxValue));;
	PlayerArmour->SetText(GetTextFromAttributeValue(PlayerAttributes->GetArmorAttribute().CurrentValue));
	PlayerMovement->SetText(PlayerMovementSpeed);
	PlayerName->SetText(CharacterName);

	ConstitutionNumber->SetText(GetTextFromAttributeValue(PlayerAttributes->GetConstitutionAttribute().CurrentValue));
	StrengthNumber->SetText(GetTextFromAttributeValue(PlayerAttributes->GetStrengthAttribute().CurrentValue));
	DexterityNumber->SetText(GetTextFromAttributeValue(PlayerAttributes->GetDexterityAttribute().CurrentValue));
	CharismaNumber->SetText(GetTextFromAttributeValue(PlayerAttributes->GetCharismaAttribute().CurrentValue));
	IntelligenceNumber->SetText(GetTextFromAttributeValue(PlayerAttributes->GetIntelligenceAttribute().CurrentValue));
	WisdomNumber->SetText(GetTextFromAttributeValue(PlayerAttributes->GetWisdomAttribute().CurrentValue));
}

//Fill in Attack Text Variables from an array of text structs
void UBaseUI::FillAttacks(TArray<FAttackTextVariables> AttackTextVariables)
{
	AttackRollText1->SetText(AttackTextVariables[0].AttackRollText);
	Attack1Name->SetText(AttackTextVariables[0].AttackNameText);
	DamageRollText1->SetText(AttackTextVariables[0].DamageRollText);

	AttackRollText2->SetText(AttackTextVariables[1].AttackRollText);
	Attack2Name->SetText(AttackTextVariables[1].AttackNameText);
	DamageRollText2->SetText(AttackTextVariables[1].DamageRollText);

	AttackRollText3->SetText(AttackTextVariables[2].AttackRollText);
	Attack3Name->SetText(AttackTextVariables[2].AttackNameText);
	DamageRollText3->SetText(AttackTextVariables[2].DamageRollText);
	
}

FText UBaseUI::GetTextFromAttributeValue(float Value)
{
	return 	FText::FromString(FString::Printf(TEXT("%.0f"), Value));
}
