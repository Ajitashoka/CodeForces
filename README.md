# MCP Tool Automation Platform - System Architecture

## 1. High-Level System Overview
The platform follows a **Microservices-based Modular Architecture** orchestrated by **FastAPI**. It separates concerns between the User Interface, Agentic Logic, and Specialized Data Handling services to ensure scalability and maintainability.

## System Architecture - Block Diagram

```mermaid
graph TB
    subgraph CLIENT["🖥️ CLIENT LAYER"]
        UI["Angular Frontend<br/>UI & Chat Interface"]
    end

    subgraph API["⚙️ FASTAPI GATEWAY<br/>Router & Orchestrator"]
        direction TB
        GW["API Gateway"]
    end

    subgraph CORE["🔧 CORE SERVICES"]
        direction TB
        AGENT["🤖 Agent Service<br/>LangGraph Workflow"]
        GIT["🐙 Git Service<br/>Clone/Pull Repos"]
        UTIL["⚙️ Utility Service<br/>Logging/Config"]
    end

    subgraph DATA["📊 DATA SERVICES"]
        direction TB
        DOC["📄 Document Service<br/>Parse API Guides"]
        INGEST["🧹 Ingestion Service<br/>Chunk & Clean"]
        EMBED["🧠 Embedding Service<br/>Vector Generation"]
    end

    subgraph STORAGE["💾 STORAGE LAYER"]
        direction TB
        QDRANT["🔍 Qdrant DB<br/>Vector Search"]
        NEO4J["📈 Neo4j DB<br/>Graph Relations"]
        LOGS["📋 Logs & Monitor"]
    end

    %% Client to API
    UI -->|WebSocket/HTTP| GW

    %% API to Core Services
    GW --> AGENT
    GW --> GIT
    GW --> UTIL

    %% API to Data Services
    GW --> DOC
    GW --> INGEST
    GW --> EMBED

    %% Core Services Flow
    AGENT -->|Query Context| QDRANT
    AGENT -->|Query Graph| NEO4J
    AGENT -->|Trigger| GIT

    %% Data Pipeline
    GIT -->|Raw Code| INGEST
    DOC -->|API Docs| INGEST
    INGEST -->|Chunks| EMBED
    EMBED -->|Vectors| QDRANT
    INGEST -->|Nodes/Edges| NEO4J

    %% Monitoring
    UTIL -.->|Monitor| LOGS

    %% Styling
    classDef client fill:#e1f5fe,stroke:#01579b,stroke-width:3px,color:#000;
    classDef gateway fill:#fff9c4,stroke:#f57f17,stroke-width:3px,color:#000;
    classDef core fill:#e8f5e9,stroke:#2e7d32,stroke-width:2px,color:#000;
    classDef data fill:#f3e5f5,stroke:#7b1fa2,stroke-width:2px,color:#000;
    classDef storage fill:#fff3e0,stroke:#ef6c00,stroke-width:3px,color:#000;

    class UI client;
    class GW gateway;
    class AGENT,GIT,UTIL core;
    class DOC,INGEST,EMBED data;
    class QDRANT,NEO4J,LOGS storage;

graph LR
    A["📥 Input Data<br/>Repo/PDF"] -->|Clone/Parse| B["🐙 Git Service<br/>📄 Doc Service"]
    B -->|Raw Data| C["🧹 Ingestion<br/>Chunk & Clean"]
    C -->|Processed Chunks| D["🧠 Embedding<br/>Generate Vectors"]
    D -->|Vectors| E["🔍 Qdrant<br/>Vector Store"]
    C -->|Nodes & Edges| F["📈 Neo4j<br/>Graph Store"]
    E -->|Similarity Search| G["🤖 Agent Service<br/>Generate Response"]
    F -->|Relationship Query| G
    G -->|Answer| H["💬 User<br/>Chat Interface"]

    classDef input fill:#ffebee,stroke:#c62828,stroke-width:2px;
    classDef process fill:#e8f5e9,stroke:#2e7d32,stroke-width:2px;
    classDef storage fill:#fff3e0,stroke:#ef6c00,stroke-width:2px;
    classDef output fill:#e1f5fe,stroke:#01579b,stroke-width:2px;

    class A input;
    class B,C,D process;
    class E,F storage;
    class G,H output;

graph TD
    U["👤 User Query"]
    U -->|Send Question| API["⚙️ FastAPI<br/>Gateway"]
    API -->|Forward| AG["🤖 Agent<br/>Service"]
    AG -->|Vector Search| QD["🔍 Qdrant"]
    AG -->|Graph Query| NJ["📈 Neo4j"]
    QD -->|Semantic Results| AG
    NJ -->|Relationships| AG
    AG -->|Process & Generate| AG
    AG -->|Response| API
    API -->|WebSocket| U
    U -->|Display| UI["💬 Chat Interface"]

    classDef user fill:#e1f5fe,stroke:#01579b,stroke-width:2px;
    classDef api fill:#fff9c4,stroke:#f57f17,stroke-width:2px;
    classDef logic fill:#e8f5e9,stroke:#2e7d32,stroke-width:2px;
    classDef db fill:#fff3e0,stroke:#ef6c00,stroke-width:2px;

    class U,UI user;
    class API api;
    class AG logic;
    class QD,NJ db;
