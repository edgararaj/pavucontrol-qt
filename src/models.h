#pragma once

#include <QtCore/QObject>

#include <nodes/NodeData>
#include <nodes/NodeDataModel>

#include <memory>

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDataModel;
using QtNodes::NodeValidationState;

/// The class can potentially incapsulate any user data which
/// need to be transferred within the Node Editor graph
class MyNodeData : public NodeData
{
public:
    NodeDataType type() const override { return NodeDataType {"Out", "Out"}; }
};

//------------------------------------------------------------------------------

/// The model dictates the number of inputs and outputs for the Node.
/// In this example it has no logic.
class MySink : public NodeDataModel
{
    Q_OBJECT

public:
    virtual ~MySink() {}

    QString caption() const override
    {
        return m_caption;
    }

    void setCaption(QString caption)
    {
        m_caption = caption;
    }

    QString name() const override
    {
        return QString("MySink");
    }

    QJsonObject save() const override
    {
        QJsonObject modelJson;

        modelJson["name"] = name();

        return modelJson;
    }

    unsigned int nPorts(PortType portType) const override
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

    NodeDataType dataType(PortType, PortIndex) const override
    {
        return MyNodeData().type();
    }

    std::shared_ptr<NodeData> outData(PortIndex) override
    {
        return std::make_shared<MyNodeData>();
    }

    void setInData(std::shared_ptr<NodeData>, int) override
    {
        //
    }

    QWidget * embeddedWidget() override { return nullptr; }

    ConnectionPolicy portInConnectionPolicy(PortIndex) const override
    {
        return ConnectionPolicy::Many;
    }

    QString m_caption;
};
