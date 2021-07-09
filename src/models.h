#pragma once

#include <QtCore/QObject>

#include <nodes/NodeData>
#include <nodes/NodeDataModel>

#include <memory>

using QtNodes::NodeData;
using QtNodes::NodeDataModel;
using QtNodes::NodeDataType;
using QtNodes::NodeValidationState;
using QtNodes::PortIndex;
using QtNodes::PortType;

/// The class can potentially incapsulate any user data which
/// need to be transferred within the Node Editor graph
class MyNodeData : public NodeData {
public:
	virtual NodeDataType type() const override { return NodeDataType { "Out", "Out" }; }
};

//------------------------------------------------------------------------------

/// The model dictates the number of inputs and outputs for the Node.
/// In this example it has no logic.
class MySink : public NodeDataModel {
	Q_OBJECT

public:
	virtual ~MySink() { }

	virtual QString caption() const override
	{
		return m_caption;
	}

	void setCaption(QString caption)
	{
		m_caption = caption;
	}

	virtual QString name() const override
	{
		return QString("MySink");
	}

	virtual QJsonObject save() const override
	{
		QJsonObject modelJson;

		modelJson["name"] = name();

		return modelJson;
	}

	virtual unsigned int nPorts(PortType portType) const override
	{
		switch (portType) {
		case PortType::In:
			return 0;
		case PortType::Out:
			return 1;
		default:
			Q_UNREACHABLE();
		}
	}

	virtual NodeDataType dataType(PortType, PortIndex) const override
	{
		return MyNodeData().type();
	}

	virtual std::shared_ptr<NodeData> outData(PortIndex) override
	{
		return std::make_shared<MyNodeData>();
	}

	virtual void setInData(std::shared_ptr<NodeData>, int) override
	{
		//
	}

	virtual QWidget* embeddedWidget() override { return nullptr; }

	virtual ConnectionPolicy portInConnectionPolicy(PortIndex) const override
	{
		return ConnectionPolicy::Many;
	}

	QString m_caption;
};
