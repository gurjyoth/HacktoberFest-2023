import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.datasets import load_wine
from sklearn.svm import SVC
from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn.metrics import classification_report, confusion_matrix
import joblib

# Load the wine dataset
wine_data, wine_target = load_wine(return_X_y=True)

# Split the dataset into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(wine_data, wine_target, test_size=0.25, random_state=42)

# Create the SVM model with a linear kernel
svm = SVC(kernel='linear')

# Train the model
svm.fit(X_train, y_train)

# Predict the test set
y_pred = svm.predict(X_test)

# Print the classification report
print("Classification Report:\n")
print(classification_report(y_test, y_pred))

# Print the confusion matrix
conf_matrix = confusion_matrix(y_test, y_pred)
print("Confusion Matrix:\n", conf_matrix)

# Visualize the confusion matrix using seaborn
plt.figure(figsize=(8, 6))
sns.heatmap(conf_matrix, annot=True, fmt='d', cmap='Blues', xticklabels=np.unique(wine_target), yticklabels=np.unique(wine_target))
plt.title('Confusion Matrix')
plt.xlabel('Predicted')
plt.ylabel('Actual')
plt.show()

# Hyperparameter tuning using GridSearchCV
param_grid = {
    'C': [0.1, 1, 10, 100],
    'gamma': ['scale', 'auto', 0.01, 0.1, 1],
    'kernel': ['linear', 'rbf']
}

grid_search = GridSearchCV(SVC(), param_grid, refit=True, verbose=2)
grid_search.fit(X_train, y_train)

# Print the best parameters found by GridSearchCV
print("Best Parameters from Grid Search:\n", grid_search.best_params_)

# Predict using the best model from GridSearchCV
best_model = grid_search.best_estimator_
y_pred_best = best_model.predict(X_test)

# Print the classification report for the best model
print("Classification Report for Best Model:\n")
print(classification_report(y_test, y_pred_best))

# Save the model to a file
joblib.dump(best_model, 'svm_wine_model.pkl')
print("Model saved as 'svm_wine_model.pkl'.")

# Load the model from the file (for demonstration)
loaded_model = joblib.load('svm_wine_model.pkl')
print("Model loaded from 'svm_wine_model.pkl'.")
