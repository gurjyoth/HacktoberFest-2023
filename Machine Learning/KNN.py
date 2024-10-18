import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn.preprocessing import LabelEncoder
from sklearn.metrics import classification_report, confusion_matrix

# Load the Mushroom dataset
df = pd.read_csv('Mushroom.csv')

# Display the first few rows of the dataset
print("First few rows of the dataset:")
print(df.head())

# Check for missing values and basic info
print("\nDataset Info:")
print(df.info())

# Visualize the class distribution
plt.figure(figsize=(8, 5))
sns.countplot(x='class', data=df)
plt.title('Class Distribution (Edible vs Poisonous)')
plt.xlabel('Class')
plt.ylabel('Count')
plt.xticks(ticks=[0, 1], labels=['Edible', 'Poisonous'])
plt.show()

# Preprocessing data
le = LabelEncoder()
columns = df.columns.tolist()  # Get all column names
for column in columns:
    df[column] = le.fit_transform(df[column])  # Encode all columns

# Split the data into features and target variable
X = df.drop('class', axis=1)
y = df['class']

# Split the data into training/testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.25, random_state=42)

# Create KNN model
classifier = KNeighborsClassifier()

# Hyperparameter tuning using GridSearchCV
param_grid = {
    'n_neighbors': [3, 5, 7, 9, 11],
    'weights': ['uniform', 'distance'],
    'metric': ['euclidean', 'manhattan']
}

grid_search = GridSearchCV(classifier, param_grid, cv=5, verbose=2, n_jobs=-1)
grid_search.fit(X_train, y_train)

# Best parameters from Grid Search
print("\nBest parameters from Grid Search:")
print(grid_search.best_params_)

# Train the model with the best parameters
best_classifier = grid_search.best_estimator_
best_classifier.fit(X_train, y_train)

# Predict for test set
y_pred = best_classifier.predict(X_test)

# Print the classification report
target_names = ["Edible", "Poisonous"]
print("\nClassification Report:")
print(classification_report(y_test, y_pred, target_names=target_names))

# Confusion matrix
conf_matrix = confusion_matrix(y_test, y_pred)
plt.figure(figsize=(8, 6))
sns.heatmap(conf_matrix, annot=True, fmt='d', cmap='Blues', xticklabels=target_names, yticklabels=target_names)
plt.title('Confusion Matrix')
plt.xlabel('Predicted')
plt.ylabel('Actual')
plt.show()

# Feature importance (using a simple method based on KNN)
feature_importance = pd.DataFrame({
    'Feature': X.columns,
    'Importance': [np.mean(best_classifier.kneighbors(X_train.values, n_neighbors=best_classifier.n_neighbors)[1], axis=1)]
})
feature_importance = feature_importance.sort_values(by='Importance', ascending=False)

print("\nFeature Importance:")
print(feature_importance)
