// Fill out your copyright notice in the Description page of Project Settings.


#include "GameStatics.h"
#include "AttributesComponent.h"


FAttributeChangeResult UGameStatics::TryDamageActor(AActor* HitInstigator, AActor* Target, float Damage)
{
	if (UAttributesComponent* Attributes = UAttributesComponent::GetAttributesComponent(Target))
	{
		return Attributes->DamageActor(HitInstigator, Damage);
	}

	return FAttributeChangeResult::MakeFailed("Target does not have health.");
}

FAttributeChangeResult UGameStatics::TryHealActor(AActor* HitInstigator, AActor* Target, float HealAmount)
{
	if (UAttributesComponent* Attributes = UAttributesComponent::GetAttributesComponent(Target))
	{
		return Attributes->HealActor(HitInstigator, HealAmount);
	}

	return FAttributeChangeResult::MakeFailed("Target does not have health.");
}

float UGameStatics::GetPercentageOfMaxValue(const FAttribute& Attribute)
{
	return Attribute.CurrentValue / Attribute.MaxValue;
}

float UGameStatics::GetCurrentAttributeValue(const FAttribute& Attribute)
{
	return Attribute.CurrentValue;
}