#include "RecipeList.h"

//Declaration
RecipeList::RecipeList(){
  currentplace = 0;
  current = new Recipe();
  front = current;
  back = current;
}


//setters
void RecipeList::addRecipe(){

    std::string rName;
    int cTime;
    int pTime;
    bool ingredientInput = false;

    std::string input;

    std::cout << "Input recipe name: ";
    std::getline (std::cin, rName);
    std::cout << std::endl;

    std::cout << "Input cooking time: ";
    std::cin >> cTime;
    std::cout << std::endl;

    std::cout << "Input preparation time: ";
    std::cin >> pTime;
    std::cout << std::endl;

    // Creates new Recipe object with rName, cTime, pTime
    // Ingredient and amount added to vectors in while loop
    Recipe* temp = new Recipe(rName, cTime, pTime);
    if (temp == NULL){
      std::cout << "error with new recipe" << std::endl;
      abort();
    }

    std::cout << "Input ingredient name with amount and unit after a :\n";
    std::cout << "Example: water:10ml\n";
    std::cout << "When finished inputting ingredients, type exit to leave ingredient input\n";

    while(ingredientInput == false){
      char c = ':';
      std::getline(std::cin, input);
      if (input != "exit"){
        size_t location = input.find(c);
        std::string tempName = input.substr(0, location);
        std::string tempAmount = input.substr(location + 1, input.size() - location);
        temp->addIngredient(tempName);
        temp->addIngredientAmount(tempAmount);
      }
      else{
        ingredientInput = true;
      }
    }
    listRecipe.push_back(*temp);
    if (listRecipe.front().getRecipeName() == rName){
      std::cout << "Successfully pushed back " << rName << std::endl;
    }
}

void RecipeList::removeRecipe(std::string rName){
  for (auto i = listRecipe.begin(); i != listRecipe.end(); i++){
    if (i->getRecipeName() == rName){
      std::cout << "Found " << rName << " in list. Now removing" << std::endl;
      listRecipe.erase(i);
      listRecipe.shrink_to_fit();
      return;
    }
  }
  std::cout << rName << " not found in list." << std::endl;
}
//getters
int RecipeList::recipeAmount(){
  return listRecipe.size();
}

Recipe* RecipeList::getCurrentRecipe(){
  return current;
}

int RecipeList::findCurrentSpot(int val){

}

Recipe* RecipeList::findRecipe(std::string rName){
  for (auto i = listRecipe.begin(); i != listRecipe.end(); i++){
    if (i->getRecipeName() == rName){
      std::cout << rName << " found in list\n";
      //TODO Find a way to convert iterator to reference of element in vector
      Recipe* ret = listRecipe.at(i);
      return ret;
    }
  }
  std::cout << rName << " not found in list\n";
}
