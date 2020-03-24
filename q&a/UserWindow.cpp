#include "UserWindow.h"

UserWindow::UserWindow(Session &session, string user, QWidget *parent)
	: session{ session }, user(user), QWidget(parent)
{
	ui.setupUi(this);
	
	this->connect(this->ui.QuestionList, &QListWidget::itemClicked, this, &UserWindow::showAnswers);
	this->connect(this->ui.QuestionButton, &QPushButton::clicked, this, &UserWindow::addQuestion);
	this->connect(this->ui.AnswerButton, &QPushButton::clicked, this, &UserWindow::addAnswer);
	
	this->session.addObserver(this);

	this->setWindowTitle(QString::fromStdString(this->getUser()));
	this->populateList();
	this->show();



}

UserWindow::~UserWindow()
{

}

void UserWindow::populateList(){
	this->ui.QuestionList->clear();
	
	vector<Question> q=this->session.getQuestions();
	for (auto item : q)
		this->ui.QuestionList->addItem(QString::fromStdString(item.toString()));
}

void UserWindow::showAnswers()
{
	this->ui.AnswerList->clear();
	
	for (int i=0; i<this->session.getQuestions().size(); i++)
		if (this->ui.QuestionList->item(i)->isSelected()) {
			vector<Answer> a = this->session.getAnswers();
			vector<Answer> result;

			string id = this->session.getQuestions().at(i).getId();
			for (auto ans : a)
				if (ans.getQuestionId() == id)
					result.push_back(ans);
		
			this->ui.AnswerList->clear();
			for (auto ans : result)
				this->ui.AnswerList->addItem(QString::fromStdString(ans.toString()));
		}
	
	

}

void UserWindow::addQuestion()
{
	QString text = this->ui.QuestionLine->text();
	
	this->session.addQuestion(this->user, text.toStdString());
}

void UserWindow::addAnswer()
{
	int i; string id;
	
	for (int i = 0; i < this->session.getQuestions().size(); i++)
		if (this->ui.QuestionList->item(i)->isSelected())
			id=this->session.getQuestions().at(i).getId();

	QString text = this->ui.AnswerLine->text();

	this->session.addAnswer(this->user, text.toStdString(), id);


}
