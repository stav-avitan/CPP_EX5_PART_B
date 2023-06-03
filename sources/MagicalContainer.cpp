#include "MagicalContainer.hpp"
#include <iostream>

using namespace ariel;
using namespace std;

MagicalContainer::MagicalContainer() {}

void MagicalContainer::addElement(int element)
{
}

void MagicalContainer::removeElement(int element)
{
}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container, size_t index): container(container), currentIndex(index) {}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &cont): container(cont), currentIndex(0) {}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other): container(other.container), currentIndex(other.currentIndex) {}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other) {
	return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const {
	return false;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const {
	return false;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const {
	return false;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const {
	return false;
}

int MagicalContainer::AscendingIterator::operator*() const {
	return 0;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
	currentIndex++;
	return *this;
}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container, size_t index): container(container), currentIndex(index) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &cont): container(cont), currentIndex(0) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other): container(other.container), currentIndex(other.currentIndex) {}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other) {
	return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const {
	return false;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const {
	return false;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const {
	return false;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const {
	return false;
}

int MagicalContainer::SideCrossIterator::operator*() const {
	return 0;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
	currentIndex++;
	return *this;
}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container, size_t index): container(container), currentIndex(index) {}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &cont): container(cont), currentIndex(0) {}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other): container(other.container), currentIndex(other.currentIndex) {}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other) {
	return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const {
	return false;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const {
	return false;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const {
	return false;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const {
	return false;
}

int MagicalContainer::PrimeIterator::operator*() const {
	return 0;
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
	currentIndex++;
	return *this;
}