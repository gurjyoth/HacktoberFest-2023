import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score
import seaborn as sns

# Fetch the dataset
df = pd.read_csv('FoodTruck.csv')

# Display the first few rows of the dataframe
print("First few rows of the dataset:")
print(df.head())

# Check for missing values
print("\nMissing values in the dataset:")
print(df.isnull().sum())

# Visualize the distribution of the data
plt.figure(figsize=(10, 5))
sns.histplot(df['food_truck_profit'], bins=20, kde=True)
plt.title('Distribution of Food Truck Profit')
plt.xlabel('Food Truck Profit')
plt.ylabel('Frequency')
plt.show()

# Split the dataset into features and target variable
X = df[['city_population']]
y = df['food_truck_profit']

# Split the dataset into train and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=42, test_size=0.25)

# Load the model
model = LinearRegression()

# Train the model
model.fit(X_train, y_train)

# Predict for the test set
y_pred = model.predict(X_test)

# Evaluate the model
mse = mean_squared_error(y_test, y_pred)
r2 = r2_score(y_test, y_pred)
print(f"\nMean Squared Error: {mse:.2f}")
print(f"R^2 Score: {r2:.2f}")

# Plot for visualization
plt.figure(figsize=(12, 6))
plt.scatter(X_test, y_test, color='blue', label='Test Data', alpha=0.6)
plt.scatter(X_train, y_train, color='green', label='Train Data', alpha=0.6)
plt.plot(X_test, y_pred, color='red', linewidth=2, label='Predicted Line')
plt.title('City Population vs Food Truck Profit')
plt.xlabel('City Population')
plt.ylabel('Food Truck Profit')
plt.legend()
plt.grid()
plt.show()

# Show the coefficients of the model
print(f"\nIntercept: {model.intercept_}")
print(f"Coefficient: {model.coef_[0]}")

# Predicting new values (optional)
new_populations = np.array([[50000], [100000], [150000]])  # Example new populations
predicted_profits = model.predict(new_populations)
for population, profit in zip(new_populations, predicted_profits):
    print(f"Predicted profit for city population {population[0]}: ${profit[0]:.2f}")
